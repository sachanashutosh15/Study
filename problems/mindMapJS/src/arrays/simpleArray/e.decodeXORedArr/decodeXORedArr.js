import * as inputs from '../../utilities/utility.js';
import readline from 'readline';

const rl = readline.createInterface({
  input: process.stdin,
  output: process.stdout,
});

async function main() {
  const sizeOfEncodedArr = await inputs.get_int("Provide size of encoded arr", rl);
  const encodedArr = Array(sizeOfEncodedArr).fill(0);
  for (let i = 0; i < sizeOfEncodedArr; i++) {
    encodedArr[i] = await inputs.get_int(`Enter element ${i}`, rl);
  }
  const first = await inputs.get_int("Enter value of first", rl);
  const result = decode(encodedArr, first);
  console.log(result);
  rl.close();
}

main();

var decode = function(encoded, first) {
  const result = Array(encoded.length + 1).fill(0);
  result[0] = first;
  for (let i = 0; i < encoded.length; i++) {
    result[i + 1] = result[i] ^ encoded[i];
  }
  return result;
};