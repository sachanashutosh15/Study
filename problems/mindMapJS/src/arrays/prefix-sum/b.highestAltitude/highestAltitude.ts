import * as inputs from "../../../utilities/utility";
import readline from "readline";

const rl = readline.createInterface({
  input: process.stdin,
  output: process.stdout,
});

async function main() {
  const arrLen = await inputs.get_int("Provide the length of gains arr", rl);
  const gainArr: number[] = Array(arrLen).fill(0);
  for (let i = 0; i < arrLen; i++) {
    gainArr[i] = await inputs.get_int(`Provide element ${i}`, rl);
  }
  const result = largestAltitude(gainArr);
  console.log("Highest altitude:", result);
  rl.close();
}

main();

function largestAltitude(gain: number[]): number {
  let highestAltitude = 0;
  let currentAltitude = 0;
  for (let i = 0; i < gain.length; i++) {
    currentAltitude += gain[i];
    if (currentAltitude > highestAltitude) {
      highestAltitude = currentAltitude;
    }
  }
  return highestAltitude;
}
