// const fs = require('fs')
// fs.writeFileSync('note.txt', 'This file was created by me !')
// fs.appendFileSync('note.txt', ' This will be appended now !')

// const { require } = require("yargs")

// const getNotes = require('./notes.js')
// const msg = getNotes()
// console.log(msg)

// const validator = require('validator')
// console.log(validator.isURL('https://www.google.co.in/'))
// console.log(validator.isEmail('1305.vikaskr@gmail.com'))

// const chalk = require('chalk')
// const { string } = require('yargs')
// console.log(chalk.green('Success!'))

// console.log(process.argv)

// const operation = process.argv[2]
// if(operation === 'add'){
//     console.log(chalk.green('adding!'))
// }else if(operation === 'remove'){
//     console.log(chalk.black('removing!'))
// }else{
//     console.log(chalk.red.bold('choose operation wisely!\nTry Again!!'))
// }

// console.log(chalk.green.italic('hello world i am back with an bang!'))

// const yargs = require('yargs')
// console.log(process.argv)


const yargs = require('yargs')
const chalk = require('chalk')
const notes = require('./notes.js')

yargs.version('1.1.0')

yargs.command({
    command: 'add',
    describe: 'Add a new note',
    builder: {
        title: {
            describe: 'Note title',
            demandOption: true,
            type: 'string'
        },
        body: {
            describe: 'Note body',
            demandOption: true,
            type: 'string'
        }
    },
    handler(argv) {
        notes.addNote(argv.title, argv.body)
    }
})

yargs.command({
    command: 'remove',
    describe: 'Remove a note',
    builder: {
        title: {
            describe: 'Note title',
            demandOption: true,
            type: 'string'
        }
    },
    handler(argv) {
        notes.removeNote(argv.title)
    }
})

yargs.command({
    command: 'list',
    describe: 'List your note',
    handler() {
        notes.listNotes()
    }
})

yargs.command({
    command: 'read',
    describe: 'Read a note',
    builder: {
        title: {
            describe: 'Note title',
            demandOption: true,
            type: 'string' 
        }
    },
    handler(argv) {
        notes.readNode(argv.title)
    }
})

yargs.parse()