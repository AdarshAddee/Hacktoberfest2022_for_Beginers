function myFunction(){
    var randomNumber1 = Math.floor(Math.random()*6) + 1;
    var img1 = document.querySelectorAll("img")[0];
    img1.setAttribute("src", "images/dice" + randomNumber1 + ".png");

    var randomNumber2 = Math.floor(Math.random()*6) + 1;
    var img2 = document.querySelectorAll("img")[1];
    img2.setAttribute("src", "images/dice" + randomNumber2 + ".png");

    var Heading = document.querySelector(".heading");
    if(randomNumber1>randomNumber2){
        Heading.innerHTML = "🚩 Player 1 Wins"
    } else if(randomNumber1<randomNumber2){
        Heading.innerHTML = "Player 2 Wins 🚩"
    } else{
        Heading.innerHTML = "Draw!" 
    }
}

document.addEventListener("keypress", myFunction);

// document.querySelector("html").addEventListener("click", myFunction);