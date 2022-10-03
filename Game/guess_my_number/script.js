'use strict';

//document.querySelector('.message').textContent = '🎉🎉 Correct Number.';
 var score = 20;
//var get;
let got = Math.trunc(Math.random()*20) +1;
let highScore = 0;


    document.querySelector('.check').addEventListener('click',function(){
        const guess = Number(document.querySelector('.guess').value);
        
        if(!guess){
            document.querySelector('.message').textContent ='⛔ No Number';
        }
        else if(guess===got){
            
            
            document.querySelector('.message').textContent = '🎉🎉 Correct Number.';
            document.querySelector('.score').textContent = score;
            document.querySelector('.number').textContent = got;
            
            document.querySelector('body').style.backgroundColor = 'green';
            document.querySelector('.number').style.width = '30rem';
            if(score>highScore)
            {
                highScore=score;
                document.querySelector('.highscore').textContent= highScore;
            }
            
        }
        else if(guess>got){
            if(score<=1){
                document.querySelector('.message').textContent = '😭 You lose';
                score=0;
                document.querySelector('.score').textContent = score;
            }
            else{document.querySelector('.message').textContent = 'Too High';
            score--;
            document.querySelector('.score').textContent = score;}
        }
        else if(guess<got){
            if(score<=1){
                document.querySelector('.message').textContent = '😭 You lose';
                score=0;
                document.querySelector('.score').textContent = score;
            }
           else{ document.querySelector('.message').textContent = 'Too Low';
            score--;
            document.querySelector('.score').textContent = score;}
        }
        
       
    })
    document.querySelector('.again').addEventListener('click',function(){
        score=20;
        document.querySelector('.score').textContent = score;
        got = Math.trunc(Math.random()*20) +1;
        document.querySelector('.message').textContent = 'Start Guessing...';
        document.querySelector('.number').style.width = '15rem';
        document.querySelector('body').style.backgroundColor = 'black';
        document.querySelector('.number').textContent = "?" ;
        document.querySelector('.guess').value = ' ';

    })
