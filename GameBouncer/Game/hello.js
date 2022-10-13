console.log('js started only for you');
var canvas = document.getElementById("mycanvas");
var ctx = canvas.getContext("2d");
var ballRadius = 10;
var x = canvas.width/2;
var y = canvas.height-30;
var dx = 2;
var dy = -2;
var paddleHeight = 10;
var paddleWidth = 75;
var paddleX = (canvas.width-paddleWidth)/2;
var rightPressed = false;
var leftPressed = false;
var score = 0;
console.log('js started only for you');

function keyDownHandler(e) {
if(e.keyCode == 39) {
    rightPressed = true;
}
else if(e.keyCode == 37) {
    leftPressed = true;
}
}
function keyUpHandler(e) {
if(e.keyCode == 39) {
    rightPressed = false;
}
else if(e.keyCode == 37) {
    leftPressed = false;
}
}

function drawBall() {
ctx.beginPath();
ctx.arc(x, y, ballRadius, 0, Math.PI*2);
ctx.fillStyle = "#0095DD";
ctx.fill();
ctx.closePath();
}
function drawPaddle() {
ctx.beginPath();
ctx.rect(paddleX, canvas.height-paddleHeight, paddleWidth, paddleHeight);
ctx.fillStyle = "#0095DD";
ctx.fill();
ctx.closePath();
}

function draw() {
ctx.clearRect(0, 0, canvas.width, canvas.height);
drawBall();
drawPaddle();

if(x + dx > canvas.width-ballRadius || x + dx < ballRadius) {
        dx = -dx;
        score=score+20;
    }
    if(y + dy < ballRadius) {
        dy = -dy;
        score=score+20;
    }
    else if(y + dy > canvas.height-ballRadius) {
        if(x > paddleX && x < paddleX + paddleWidth) {
            dy = -dy;
            score=score+30;
        }
        else {
            alert("SORRY GAME OVER! " + "\n"+"Try Hard" +"\n"+" Your score is :" + score);
            document.location.reload();
        }
    }

    if(rightPressed && paddleX < canvas.width-paddleWidth) {
        paddleX += 7;
    }
    else if(leftPressed && paddleX > 0) {
        paddleX -= 7;
    }

    x += dx;
    y += dy;
    function drawScore() {
    ctx.font = "16px Arial";
    ctx.fillStyle = "#0095DD";
    ctx.fillText("Score: "+score, 8, 20);
}
  drawScore();
}
document.addEventListener("keydown", keyDownHandler, false);
document.addEventListener("keyup", keyUpHandler, false);

setInterval(draw, 10);
