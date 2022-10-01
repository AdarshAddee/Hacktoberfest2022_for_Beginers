let startbutton = document.querySelector(".btn");
let box = document.querySelector(".box");
let canvas = document.querySelector(".board");
let tool = canvas.getContext("2d");
let scoretext=document.getElementById("scoretext");
let meter=document.querySelector(".meter span");
let restartbtn=document.querySelector(".restart");
let aftergamescore=document.getElementById("after_score");
let bulletspeed=8,coronaspeed=2,coronasize=60,bulletsize=8,particlefadeoutTime=0.01;
let score=0;
let count=100;
let how_to_play=document.querySelector(".howPlay");
canvas.height = window.innerHeight;
canvas.width = window.innerWidth;

let spaceimg = new Image();
spaceimg.src = "space.jpg";
let earthimg = new Image();
earthimg.src = "earth.png";
let coronaimg = new Image();
coronaimg.src = "newcorona.png";
let bullets = [];
let coronas = [];
let particles = [];

class particle {
    constructor(x, y, radius, velocity) {
        this.x = x;
        this.y = y;
        this.radius = radius;
        this.velocity = velocity;
        this.alpha = 1; // set opacity of particle
    }

    draw() {
        tool.save();// as we use alpha so we have to save old state 
        tool.globalAlpha = this.alpha;
        tool.beginPath();
        tool.fillStyle = "white";
        tool.arc(this.x, this.y, this.radius, 0, Math.PI * 2, false);
        tool.fill();
        tool.restore();
    }
    update() {
        this.draw();
        this.x = this.x + this.velocity.x;
        this.y = this.y + this.velocity.y;
        this.alpha -= particlefadeoutTime; // every time we decrease opacity of particle
    }

}

class planet {

    constructor(x, y, width, height) {
        this.x = x;
        this.y = y;
        this.width = width;
        this.height = height;
        this.velocity = this.velocity;
    }

    draw() {

        tool.drawImage(earthimg, this.x, this.y, this.width, this.height);
    }

}
class corona {

    constructor(x, y, width, height, velocity) {
        this.x = x;
        this.y = y;
        this.width = width;
        this.height = height;
        this.velocity = velocity;
    }

    draw() {
        //    tool.fillStyle='white';

        tool.drawImage(coronaimg, this.x, this.y, this.width, this.height);
    }
    update() {
        this.draw();
        this.x += this.velocity.x;
        this.y += this.velocity.y;
    }

}
class Bullet {

    constructor(x, y, width, height, velocity) {
        this.x = x;
        this.y = y;
        this.width = width;
        this.height = height;
        this.velocity = velocity;
    }

    draw() {
        tool.fillStyle = 'white';

        tool.fillRect(this.x, this.y, this.width, this.height);
    }
    update() {
        this.draw();
        this.x += this.velocity.x;
        this.y += this.velocity.y;
    }

}


function coloccur(entity1, entity2) {

    let l1 = entity1.x, l2 = entity2.x;
    let r1 = entity1.x + entity1.width, r2 = entity2.x + entity2.width;
    let t1 = entity1.y + entity1.height, t2 = entity2.y + entity2.height;
    let b1 = entity1.y, b2 = entity2.y;


    if (l1 < r2 && l2 < r1 && t1 > b2 && t2 > b1)
        return true;
    return false;

}

function createCorona() {
    setInterval(() => {
        let x, y;

        let delta = Math.random();
        console.log(delta);
        if (delta < 0.5) {
            x = Math.random() < 0.5 ? 0 : canvas.width;
            y = Math.random() * canvas.height;
        }
        else {
            y = Math.random() < 0.5 ? 0 : canvas.height;
            x = Math.random() * canvas.width;
        }
        let angle = Math.atan2(canvas.height / 2 - y, canvas.width / 2 - x);
        let velocity = {
            x: Math.cos(angle)*coronaspeed,
            y: Math.sin(angle)*coronaspeed
        }
        let coroona = new corona(x, y, coronasize, coronasize, velocity);
        coronas.push(coroona);
         

    }, 1000)
}

let animid;
function levelhardbytime(){
    setInterval(()=>{
     
        coronaspeed+=0.08;
        bulletspeed+=0.1;
        // particlefadeoutTime+=0.0002;
        console.log(`speed bost  ${coronaspeed}`);
        console.log(coronaspeed+" "+bulletspeed);

    },20000)
}
function animate() {
    tool.clearRect(0, 0, window.innerWidth, window.innerHeight);
    tool.drawImage(spaceimg, 0, 0, canvas.width, canvas.height);
    let height = 70, width = 70, ex_cordinate = canvas.width / 2, ey_cordinate = canvas.height / 2;
    let earth = new planet(ex_cordinate, ey_cordinate, width, height);
    earth.draw();

    particles.forEach((particle, index) => {
        if (particle.alpha <= 0) {
            setTimeout(() => {
                particles.splice(index, 1);
            }, 0)

        } else {
            particle.update();
        }
    })

    let blength = bullets.length;
    for (let i = 0; i < blength; i++) {

        bullets[i].update();

        if (bullets[i].x < 0 || bullets[i].y < 0 || bullets[i].x > canvas.width || bullets[i].y > canvas.height) {
            setTimeout(() => {
                bullets.splice(i, 1);
            })

        }
    }



    

    coronas.forEach((coronaindi,index)=>{

       

            coronaindi.update();
            let enemy = coronaindi;
            if (coloccur(earth, enemy)) {
               count-=20;
               meter.style.width=`${count}%`;
               setTimeout(()=>{coronas.splice(index,1);
            },0)
               
               if(count==0)
               {
                cancelAnimationFrame(animid);
                // alert("Game Over");
                restart();
               }
            }
    
            bullets.forEach((bullet, bulletindex) => {
                if (coloccur(enemy, bullet)) {
                   
                    //bullet colloid with corrona so both of them shoul erase
    
    
                    // also for effect generate particles which shows effect like explosion
    
                    // and insert in particles array and after each frame rate it will update itself
                    for (let i = 0; i < enemy.width * 10; i++) {
                        console.log("bullets colloid with corona");
                        particles.push(new particle(bullet.x, bullet.y, Math.random() * 2, {
                            x: (Math.random() - 0.5) * (Math.random() * 5),
                            y: (Math.random() - 0.5) * (Math.random() * 5)
                        }))
    
    
                    }
    
    
                    setTimeout(() => {
                        coronas.splice(index, 1);
                        bullets.splice(bulletindex, 1);
                    }, 0)
                    score+=100;
                    scoretext.innerText=score;
                }
            })
    
    
    
        

    })
    




    console.log(blength);

    requestAnimationFrame(animate);

}
startbutton.addEventListener("click", (e) => {
    how_to_play.style.display="none";
    e.stopImmediatePropagation();
    box.style.display = "none";
    tool.fillRect(0, 0, canvas.width, canvas.height);

    animate();
    createCorona();
    levelhardbytime();
    window.addEventListener("click", (e) => {
        // console.log(e);
        let angle = Math.atan2(e.clientY - canvas.height / 2, e.clientX - canvas.width / 2);
        let velocity = {
            x: Math.cos(angle) * bulletspeed,
            y: Math.sin(angle) * bulletspeed
        }

        let bullet = new Bullet(canvas.width / 2 + 25, canvas.height / 2 + 25, bulletsize, bulletsize, velocity);
        bullet.draw();
        bullets.push(bullet);
    })


})



window.addEventListener("resize",function(){
window.location.reload();

})


function restart(){
 restartbtn.style.display ="block";
 startbutton.style.display= "none";
 box.style.display="flex";
 box.style.left="78vh";
//   how_to_play.style.display="none";
 aftergamescore.innerText=score;
 aftergamescore.parentElement.style.display="block";
 meter.parentElement.style.display="none";
 document.body.style.backgroundColor="white";
 canvas.height="0px";
 restartbtn.addEventListener("click",function(){
    window.location.reload();
 }
 )
}

