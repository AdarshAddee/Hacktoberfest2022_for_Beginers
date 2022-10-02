const valuesForComputer = {
    0: "Snake",
    1: "Water",
    2: "Gun"
}
const valuesForHuman = {
    "S": "Snake",
    "W": "Water",
    "G": "Gun"
}
let countComputer = 0;
let countHuman = 0;
let wantMore;
console.log("Enter S For Snake, W for Water and G For Gun !!!")
do {
    const random = Math.floor(Math.random() * 3);
    const computerValue = valuesForComputer[random];

    const humanInput = prompt("Enter Your Choice : ")
    const humanValue = valuesForHuman[humanInput]
    if (computerValue === humanValue) {
        console.log("It is a Clash !!!")
    } else {
        if (computerValue === "Snake" && humanValue === "Water") {
            console.log("Computer Won !!!")
            console.log(`Computer Got ${computerValue} and you got ${humanValue} `)
            countComputer++;
        } else if (computerValue === "Water" && humanValue === "Gun") {
            console.log("Computer Won !!!")
            console.log(`Computer Got ${computerValue} and you got ${humanValue} `)
            countComputer++;
        } else if (computerValue === "Gun" && humanValue === "Snake") {
            console.log("Computer Won !!!")
            console.log(`Computer Got ${computerValue} and you got ${humanValue} `)
            countComputer++;
        } else {
            console.log("You Won !!!")
            console.log(`Computer Got ${computerValue} and you got ${humanValue} `)
            countHuman++;
        }
    }
    wantMore = confirm("Want To play More ? ")
} while (wantMore != false);
console.log(`Computer Score : ${countComputer} \nYour Score: ${countHuman}`)
console.log("Thanks For Playing !!! :)")