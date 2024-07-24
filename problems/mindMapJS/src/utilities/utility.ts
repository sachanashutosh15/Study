import readline from "readline";

export function get_int(
  message: string,
  rl: readline.Interface
): Promise<number> {
  return new Promise((resolve) => {
    let isInputValid = false;
    rl.question(`${message}: `, (input) => {
      if (!isNaN(Number(input))) {
        isInputValid = true;
        resolve(Number(input));
      } else {
        console.log("Please provide valid input.");
        get_int(message, rl).then(resolve);
      }
    });
  });
}
