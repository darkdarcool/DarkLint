import chalk from 'chalk'
import fs from 'fs'
import { createRequire } from 'module';

const require = createRequire(import.meta.url);
const darklint = require('../build/Release/main.node');

const args = process.argv.splice(2);

let text = `	Hello

Well, wow wow
I just dont get it
This is just dumb
`

darklint.lint(text)