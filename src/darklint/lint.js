import err from './utils/err.js';
import * as words from './utils/word.js'
import chalk from 'chalk'

function getBeforePlus(str, word){

    return str.substring(0, str.indexOf(word)); 
   /* This gets a substring from the beginning of the string 
      to the first index of the character "+".
   */

}

export default function darklint(content) {
	if (content[0][0] != "\t") {
		err('Tabs', 'Always indent any text!');
	}
	const text = content.split('\n');
	for (let i = 0; i < text.length; i++) {
		let line = text[i];
		words.words.forEach((word) => {
			word = ` ${word} `
			if (line.includes(word)) {
				console.log("\x1b[34m____________________________________________________\x1b[0m")
				err('Bad words', 'Never use these words! They aren\'t good for essays, and your teacher will mark you down!');
				if (text[i - 1] != undefined) console.log(`${i - 1}: ${text[i -1]}`)
				console.log(`${i}: ${getBeforePlus(line, word)}${chalk.red.bold(line.replace(getBeforePlus(line, word), "").split(word).join(word + "\x1b[0m"))}`); // dear god help me
				for (let e = 0; e < getBeforePlus(line, word).length + `${i}`.length + 2; e++) {
					process.stdout.write(chalk.green.bold("~"))
				}
				console.log(chalk.green.bold("^"));
				if (text[i + 1] != undefined) console.log(`${i + 1}: ${text[i + 1]}`)
			}
		});
		words.contractions.forEach((word) => {
			if (line.includes(word)) {
				console.log("\x1b[34m____________________________________________________\x1b[0m")
				err('Contractions', 'Contractions should not be used and they shorten essay length. Not using them can make your essay longer!');
				if (text[i - 1] != undefined) console.log(`${i - 1}: ${text[i -1]}`)
				console.log(`${i}: ${getBeforePlus(line, word)}${chalk.red.bold(line.replace(getBeforePlus(line, word), "").split(word).join(word + "\x1b[0m"))}`); // dear god help me
				for (let e = 0; e < getBeforePlus(line, word).length + `${i}`.length + 2; e++) {
					process.stdout.write(chalk.green.bold("~"))
				}
				console.log(chalk.green.bold("^"));
				if (text[i + 1] != undefined) console.log(`${i + 1}: ${text[i + 1]}`)
			}
		});
	}
}