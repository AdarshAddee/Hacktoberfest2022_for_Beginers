function rps_game(yourchoice){
    console.log(yourchoice);
    var humanChoice, botChoice;
    humanChoice = yourchoice.id;
    botChoice = numberToChoice(randToRpsInt());
    console.log(botChoice);
    var results = decidewinner(humanChoice,botChoice);
    console.log(results);
    var message = finalmessage(results);
    console.log(message);
    frontend(yourchoice.id,botChoice,message);

}

function randToRpsInt(){
    return Math.floor(Math.random() * 3);
}

function numberToChoice(number){
    return ['rock','paper','scissors'][number];
}

function decidewinner(humanChoice,botChoice){
    var rpsdatabase = {
        'rock':{'scissors':1 , 'rock':0.5, 'paper':0},
        'paper':{'rock':1 , 'paper':0.5, 'scissors':0},
        'scissors':{'paper':1 , 'scissors':0.5, 'rock':0}
    };

    var yourscore = rpsdatabase[humanChoice][botChoice];
    var botscore = rpsdatabase[botChoice][humanChoice];

    return [yourscore,botscore];
}

function finalmessage([yourscore,botscore]){
    if(yourscore === 0){
        return {'message':'You Lost!!','color':'red'};
    }
    else if(yourscore === 0.5){
        return {'message':'You tied!!','color':'yellow'};
    }
    else {
        return {'message':'You Won!!','color':'green'};
    }
}

function frontend(humanImageChoice,botImageChoice,finalmessage){
    var imagesdatabase = {
        'rock': document.getElementById('rock').src,
        'paper': document.getElementById('paper').src,
        'scissors': document.getElementById('scissors').src 
    }

    document.getElementById('rock').remove();
    document.getElementById('paper').remove();
    document.getElementById('scissors').remove();

    var humanDiv = document.createElement('div');
    var botDiv = document.createElement('div');
    var messageDiv = document.createElement('div');

    humanDiv.innerHTML = "<img src='" + imagesdatabase[humanImageChoice] + "' height=150 width=150 style='box-shadow: 0px 10px 50px rgba(37,50,233,1);'>";
    document.getElementById('flex-box-rps-div').appendChild(humanDiv);

    messageDiv.innerHTML = "<h1 style='color: " + finalmessage['color'] + "; font-size:60px; padding: 30px;' >"+ finalmessage['message'] +"</h1>"
    document.getElementById('flex-box-rps-div').appendChild(messageDiv);

    botDiv.innerHTML = "<img src='" + imagesdatabase[botImageChoice] + "' height=150 width=150 style='box-shadow: 0px 10px 50px rgba(243,38,24,1);'> ";
    document.getElementById('flex-box-rps-div').appendChild(botDiv);

  
}
