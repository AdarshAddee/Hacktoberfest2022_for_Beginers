function date() {
    const now = new Date();

    const seconds = now.getSeconds();

    const minutes = now.getMinutes();

    const hour = now.getHours();
}

setInterval(setDate, 1000);

setDate();