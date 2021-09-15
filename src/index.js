import chalk from 'chalk'
import fs from 'fs'
import darklint from './darklint/lint.js'


const args = process.argv.splice(2);

// let text = `${fs.readFileSync(args[0], { encoding: 'utf-8' })}`



darklint(`Hello! 

My name is dark! And that's cool!
I like this!


`)