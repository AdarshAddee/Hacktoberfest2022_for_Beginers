
var randomNumber1=Math.floor(Math.random()*6)+1; //1-6

var randomImg1="dice"+randomNumber1+".png";

var source="images/"+randomImg1;

var image1=document.querySelectorAll("img")[0];

image1.setAttribute("src",source);

var randomNumber2=Math.floor(Math.random()*6)+1; //1-6

var randomImg2="dice"+randomNumber2+".png";

var source1="images/"+randomImg2;

var image2=document.querySelectorAll("img")[1];

image2.setAttribute("src",source1);

//now heading part
if(randomNumber1 > randomNumber2){
  document.querySelector("h1").innerHTML = "Player 1 Wins!!";
}
else if(randomNumber1 < randomNumber2){
  document.querySelector("h1").innerHTML = "Player 2 Wins!!" ;
}

else{
  document.querySelector("h1").innerHTML = "Draw !!! ";
}
