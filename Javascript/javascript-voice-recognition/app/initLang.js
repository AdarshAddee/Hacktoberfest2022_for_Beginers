let lang = 'en-US';
const minValue = localStorage.getItem('minValue') || 1;
localStorage.setItem('minValue', minValue);
const maxValue = localStorage.getItem('maxValue') || 100;
localStorage.setItem('maxValue', maxValue);
if (localStorage.getItem('lang')) {
  lang = localStorage.getItem('lang');
}

console.log('Language: ', lang);

const titleBig = document.querySelector('h1');
const description = document.querySelector('h3');
const enButton = document.querySelector('#en-button');
const ptButton = document.querySelector('#pt-button');

enButton.addEventListener('click', () => {
  lang = 'en-US';
  localStorage.setItem('lang', lang);
  window.location.reload();
});

ptButton.addEventListener('click', () => {
  lang = 'pt-BR';
  localStorage.setItem('lang', lang);
  window.location.reload();
});

if (lang === 'en-US') {
  enButton.classList.add('selected');
  ptButton.classList.remove('selected');
} else {
  ptButton.classList.add('selected');
  enButton.classList.remove('selected');
}

document.title = lang === 'en-US' ? 'Guess the number' : 'Adivinhe o número';

titleBig.innerHTML =
  lang === 'en-US'
    ? 'Can you guess the secret number?'
    : 'Você consegue adivinhar o número secreto?';

description.innerHTML =
  lang === 'en-US'
    ? `The secret number is between <span id="min-value">${minValue}</span> and
    <span id="max-value">${maxValue}</span>`
    : `O número secreto está entre <span id="min-value">${minValue}</span> e
    <span id="max-value">${maxValue}</span>`;
