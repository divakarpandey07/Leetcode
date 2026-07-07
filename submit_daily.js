const fs = require('fs');
const path = require('path');
const https = require('https');

const problems = require('./problems.json');
const status = require('./status.json');

const sessionCookie = process.env.LEETCODE_SESSION;
const csrfToken = process.env.LEETCODE_CSRF_TOKEN;

if (!sessionCookie || !csrfToken) {
  console.error("Missing LEETCODE_SESSION or LEETCODE_CSRF_TOKEN environment variables!");
  process.exit(1);
}

const currentIndex = status.next_problem_index;
if (currentIndex >= problems.length) {
  console.log("All 500 problems have been submitted!");
  process.exit(0);
}

const currentProblem = problems[currentIndex];
const poolPath = path.join(__dirname, '.solutions_pool', currentProblem.file);
const destPath = path.join(__dirname, currentProblem.file);

if (!fs.existsSync(poolPath)) {
  console.error(`Solution file ${currentProblem.file} not found in pool!`);
  process.exit(1);
}

const typedCode = fs.readFileSync(poolPath, 'utf8');

function submitSolution(problem, code) {
  const postData = JSON.stringify({
    lang: "cpp",
    question_id: problem.id,
    typed_code: code
  });

  const options = {
    hostname: 'leetcode.com',
    path: `/problems/${problem.slug}/submit/`,
    method: 'POST',
    headers: {
      'Cookie': `LEETCODE_SESSION=${sessionCookie}; csrftoken=${csrfToken}`,
      'x-csrftoken': csrfToken,
      'referer': `https://leetcode.com/problems/${problem.slug}/`,
      'content-type': 'application/json',
      'User-Agent': 'Mozilla/5.0 (Windows NT 10.0; Win64; x64) AppleWebKit/537.36 (KHTML, like Gecko) Chrome/120.0.0.0 Safari/537.36',
      'Content-Length': Buffer.byteLength(postData)
    }
  };

  return new Promise((resolve, reject) => {
    const req = https.request(options, (res) => {
      let data = '';
      res.on('data', (chunk) => { data += chunk; });
      res.on('end', () => {
        resolve({
          statusCode: res.statusCode,
          body: data
        });
      });
    });

    req.on('error', (e) => reject(e));
    req.write(postData);
    req.end();
  });
}

console.log(`Submitting problem: ${currentProblem.id} - ${currentProblem.title} (${currentProblem.slug})...\n`);

submitSolution(currentProblem, typedCode)
  .then(res => {
    console.log("LeetCode Submission Status Code:", res.statusCode);
    console.log("LeetCode Response:", res.body);
    
    if (res.statusCode === 200) {
      const responseBody = JSON.parse(res.body);
      if (responseBody.submission_id) {
        console.log(`\nSuccessfully submitted! Submission ID: ${responseBody.submission_id}`);
        
        // Copy the file from pool to root directory
        fs.copyFileSync(poolPath, destPath);
        console.log(`Copied ${currentProblem.file} to root directory.`);
        
        // Update status.json
        status.next_problem_index = currentIndex + 1;
        fs.writeFileSync(path.join(__dirname, 'status.json'), JSON.stringify(status, null, 2));
        console.log(`Updated status.json to next_problem_index: ${status.next_problem_index}`);
      } else {
        console.error("Submission failed, no submission_id returned.");
        process.exit(1);
      }
    } else {
      console.error("Failed to submit to LeetCode.");
      process.exit(1);
    }
  })
  .catch(err => {
    console.error("Error during submission:", err);
    process.exit(1);
  });
