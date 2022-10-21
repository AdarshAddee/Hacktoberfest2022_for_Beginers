// Github username: WaroDev (Robin Dreyer)
// Aim: Print 1 to 100 without using numbers
// Date: 10/21/2022 (21.10.2022)

// start coding

// the trick with this challenge is to somehow get a number out of a string or something
// my approach uses the ascii code of a character as a number to create an array
Array.from(Array("d".charCodeAt([].length)).keys()).forEach( i => { console.log(++i) } );
