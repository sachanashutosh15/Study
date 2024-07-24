import * as inputs from "../../../utilities/utility";
import readline from "readline";

const rl = readline.createInterface({
  input: process.stdin,
  output: process.stdout,
});

async function main() {
  const arrLen = await inputs.get_int("Provide the length of array", rl);
  const nums = Array(arrLen).fill(0);
  for (let i = 0; i < arrLen; i++) {
    nums[i] = await inputs.get_int(`Provide num ${i}`, rl);
  }
  const result = runningSum(nums);
  console.log(result);
  rl.close();
}

main();

function runningSum(nums: number[]): number[] {
  const result: number[] = Array(nums.length).fill(0);
  let sum = 0;
  for (let i = 0; i < nums.length; i++) {
    sum += nums[i];
    result[i] = sum;
  }
  return result;
}
