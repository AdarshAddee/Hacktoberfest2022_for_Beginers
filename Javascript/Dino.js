import { increamentCustomProperty, setCustomProperty, getCustomProperty } from "./updateprop.js";
const dino = document.querySelector('.dino');
const jumpSpeed = 0.45
const gravity = 0.0015
const dinoFrameCount = 2
const frameTime = 100

let isJumping
let dinoFrame
let currentFrameTime
let yvelocity

export function setupDino() {
  isJumping = false
  dinoFrame = 0
  currentFrameTime = 0
  yvelocity = 0
  setCustomProperty(dino, '--bottom', 0)
  document.removeEventListener('keydown', onJump)
  document.addEventListener('keydown', onJump)
}

export function updateDino(delta, speedScale) {
  handleRun(delta, speedScale)
  handleJump(delta)
}

export function getDinoRect() {
  return dino.getBoundingClientRect();
}

export function setDinoLose() {
  dino.src = 'imgs/dino-lose.png'
}

function handleRun(delta, speedScale) {
  if (isJumping) {
    dino.src = `imgs/dino-stationary.png`
    return
  }

  if (currentFrameTime >= frameTime) {
    dinoFrame = (dinoFrame + 1) % dinoFrameCount
    dino.src = `imgs/dino-run-${dinoFrame}.png`
    currentFrameTime -= frameTime
  }
  currentFrameTime += delta * speedScale
}

function handleJump(delta) {
  if (!isJumping) return
  increamentCustomProperty(dino, '--bottom', yvelocity * delta)
  if (getCustomProperty(dino, '--bottom') <= 0) {
    setCustomProperty(dino, '--bottom', 0)
    isJumping = false
  }
  yvelocity -= gravity * delta
}

function onJump(e) {
  if (e.code !== 'Space' || isJumping) return
  yvelocity = jumpSpeed
  isJumping = true
}

