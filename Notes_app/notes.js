const { notStrictEqual } = require('assert')
const { default: chalk } = require('chalk')
const fs = require('fs')
const { title } = require('process')

const addNote = (title, body) => {
    const notes = loadNotes()
    // const duplicateNotes = notes.filter((note) => note.title === title)
    const duplicateNote = notes.find((note) => note.title === title)

    if (!duplicateNote) {
        notes.push({
            title: title,
            body: body
        })
        saveNotes(notes)
        console.log(chalk.green.inverse('New note added!'))
    } else {
        console.log(chalk.red.inverse('Note title taken!'))
    }
}

const removeNote = (title) => {
    const notes = loadNotes()
    const notesToKeep = notes.filter((notes) => notes.title != title)
    if(notes.length > notesToKeep.length){
        console.log(chalk.green.inverse('node removed!'))
        saveNotes(notesToKeep)
    }else{
        console.log(chalk.red.inverse('no node found!'))
    }
}

const listNotes = () => {
    const notes = loadNotes()
    console.log(chalk.inverse('Your Notes!'))
    notes.forEach((note) => {
        console.log(note.title)
    })
}

const readNode = (title) => {
    const notes = loadNotes();
    const noteToDispled = notes.find((note) => note.title === title)

    if(noteToDispled){
        console.log(chalk.inverse(noteToDispled.title))
        console.log(noteToDispled.body)
    }else{
        console.log(chalk.red.inverse('Note not found!'))
    }
}

const saveNotes = (notes) => {
    const dataJSON = JSON.stringify(notes)
    fs.writeFileSync('notes.json', dataJSON)
}

const loadNotes = () => {
    try {
        const dataBuffer = fs.readFileSync('notes.json')
        const dataJSON = dataBuffer.toString()
        return JSON.parse(dataJSON)
    } catch (e) {
        return []
    }
}

module.exports = {
    addNote: addNote,
    removeNote: removeNote,
    listNotes: listNotes,
    readNode: readNode
}