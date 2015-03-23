var resultLabel = document.getElementById('result');
var initialText = resultLabel.textContent.valueOf();

var startTime = 0;
var timeDifference = 0;
var displayInterval;

function start() {
    if (startTime == 0) {
        startTime = new Date().getTime();
    }
    else {
        // 一時停止後に再開した場合は、停止した時間から再Startさせる
        startTime = new Date().getTime() - timeDifference;
    }
    clearInterval(displayInterval);
    displayInterval = setInterval('display()', 1);
}

function stop() {
    clearInterval(displayInterval);
}

function refresh() {
    clearInterval(displayInterval);
    startTime = 0;
    timeDifference = 0;
    resultLabel.textContent = initialText;
}

function display() {
    // Startを押してから表示時までの差分を取得[ms]
    timeDifference = new Date().getTime() - startTime;
    resultLabel.textContent = millisecond2hhmmssmmm(timeDifference);
}

function millisecond2hhmmssmmm(millisecond) {
    var hour = Math.floor(millisecond / (60 * 60 * 1000));
    millisecond = millisecond - (hour * 60 * 60 * 1000);
    var minute = Math.floor(millisecond / (60 * 1000));
    millisecond = millisecond - (minute * 60 * 1000);
    var second = Math.floor(millisecond / 1000);
    millisecond = millisecond - (second * 1000);

    return hour + ":" + ("0" + minute).slice(-2) + ":" + ("0" + second).slice(-2) + ":" + ("00" + millisecond).slice(-3);
}
