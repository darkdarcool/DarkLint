#!/usr/bin/env node

import chalk from 'chalk'
import fs from 'fs'
import darklint from './darklint/lint.js'


const args = process.argv.splice(2);

let text
try {
text = `${fs.readFileSync(args[0], { encoding: 'utf-8' })}`
} catch(_err) {
	console.log("File not found")
	process.exit(0)
}



darklint(`${text}`);