function display() {
    var targetNumber = document.prime.number.value;

    var i = 2;  // 検査する数字
    var j;  // 割り算する数字
    var primeFlag;
    var strings = "";

    // 素数チェック上限の数字
    while (i <= targetNumber) {
        j = 2;
        primeFlag = true;

        // 2 <= n < 素数チェック対象の数字
        while (j < i) {
            // 割り切れる数字がある場合は素数ではない
            var remainder = i % j;
            if (remainder == 0) {
                primeFlag = false;
                break;
            }
            j++;
        }

        // 割り切れていれば出力用変数に追加する
        if (primeFlag) {
            strings = strings + i + " ";
        }
        i++;
    }

    document.getElementById('result').textContent = strings;
}