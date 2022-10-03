function isGuessValid(guess) {
  const number = Number(guess);

  // check if guess is a number
  if (Number.isNaN(number)) {
    guessElement.innerHTML +=
      lang === 'en-US'
        ? '<div>Invalid value</div>'
        : '<div>Valor inválido</div>';
    return;
  }

  // Check if the guess is between 1 and 100
  if (number > maxValue || number < minValue) {
    guessElement.innerHTML +=
      lang === 'en-US'
        ? `<div>The secret number must be between ${minValue} and ${maxValue}</div>`
        : `<div>O número secreto deve estar entre ${minValue} e ${maxValue}</div>`;
    return;
  }

  // Check if the guess is correct
  if (number === secretNumber) {
    document.body.innerHTML =
      lang === 'en-US'
        ? `
    <h2>That's it!</h2>
    <h3>The secret number was ${secretNumber}</h3>

    <button id="play-again" class="btn-play-again">Play again</button>
`
        : `
<h2>Você acertou!</h2>
<h3>O número secreto era ${secretNumber}</h3>

<button id="play-again" class="btn-play-again">Jogar novamente</button>
`;
  } else if (number > secretNumber) {
    guessElement.innerHTML +=
      lang === 'en-US'
        ? '<div>The secret number is smaller <i class="fa-solid fa-down-long"></i></div>'
        : '<div>O número secreto é menor <i class="fa-solid fa-down-long"></i></div>';
  } else {
    guessElement.innerHTML +=
      lang === 'en-US'
        ? '<div>The secret number is bigger <i class="fa-solid fa-up-long"></i></div>'
        : '<div>O número secreto é maior <i class="fa-solid fa-up-long"></i></div>';
  }
}

document.body.addEventListener('click', (event) => {
  if (event.target.id === 'play-again') {
    window.location.reload();
  }
});
