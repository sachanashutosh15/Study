import * as inputs from '../../utilities/utility.js';
import readline from 'readline';

const rl = readline.createInterface({
  input: process.stdin,
  output: process.stdout
});

async function main() {
  const kidsCount = await inputs.get_int("please provide the number of kids", rl);
  const candies = [];
  for (let i = 0; i < kidsCount; i++) {
    candies.push(await inputs.get_int(`provide element ${i}`, rl));
  }
  const extraCandies = await inputs.get_int("provide number of extra candies", rl);
  const result = kidsWithCandies(candies, extraCandies);
  console.log(result);
  rl.close();
}

main();

var kidsWithCandies = function(candies, extraCandies) {
  const n = candies.length;
  const maxExceptCurr = Array(n).fill(0);
  let max = -Infinity;
  for (let i = 0; i < n; i++) {
    maxExceptCurr[i] = max;
    max = Math.max(max, candies[i]);
  }
  max = -Infinity;
  for (let i = n - 1; i >= 0; i--) {
    maxExceptCurr[i] = Math.max(max, maxExceptCurr[i]);
    max = Math.max(candies[i], max);
  }
  const result = candies.map((num, i) => {
    if (num + extraCandies >= maxExceptCurr[i]) {
      return true;
    } else {
      return false;
    }
  })
  return result;
}

// var kidsWithCandies = function(candies, extraCandies) {
//   const result = candies.map((num) => {
//     if(Math.max(num + extraCandies, ...candies) == num + extraCandies) {
//       return true;
//     } else {
//       return false;
//     }
//   })
//   return result;
// };
