const min = localStorage.getItem('minValue');
const max = localStorage.getItem('maxValue');
function getSecretNumber() {
  return parseInt(Math.random() * max + 1);
}

const secretNumber = getSecretNumber();
console.log('Secret number: ', secretNumber);

const minValueElement = document.querySelector('#min-value');
const maxValueElement = document.querySelector('#max-value');
minValueElement.innerHTML = min;
maxValueElement.innerHTML = max;
