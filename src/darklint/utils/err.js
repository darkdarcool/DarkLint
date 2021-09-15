import chalk from 'chalk'

export default function error(kind, message) {
	console.log(chalk.bgRed(kind) + " " + chalk.red.bold(message));
}