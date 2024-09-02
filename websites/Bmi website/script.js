document.addEventListener('DOMContentLoaded', function() {
    const form = document.getElementById('bmiForm');
    const resultArea = document.getElementById('result');
    const weightInput = document.getElementById('weightInput');
    const heightInput = document.getElementById('heightInput');

    form.addEventListener('submit', function(event) {
        event.preventDefault();
        calculate();
    });

    function calculate() {
        const height = parseFloat(heightInput.value);
        const weight = parseFloat(weightInput.value);

        // Check for non-numeric or empty inputs
        if (isNaN(weight) || isNaN(height) || weightInput.value.trim() === '' || heightInput.value.trim() === '') {
            displayMessage("<b>Enter valid data for height & weight</b>");
            return;
        }

        // Check for non-positive inputs
        if (weight <= 0 || height <= 0) {
            displayMessage("<b>Enter valid data for height & weight</b>");
            document.querySelector('.comment').style.display = "block";
            return;
        }

        const BMI = weight / Math.pow(height / 100, 2);
        let result = '';

        if (BMI < 18.5) {
            result = 'You are Under Weight';
        } else if (BMI >= 18.5 && BMI <= 24.9) {
            result = 'You are Normal';
        } else if (BMI >= 25 && BMI <= 29.9) {
            result = 'You are Over Weight';
        } else if (BMI >= 30 && BMI <= 34.9) {
            result = 'You are on Obesity (Lvl 1)';
        } else if (BMI >= 35 && BMI <= 39.9) {
            result = 'You are on Obesity (Lvl 2)';
        } else if (BMI > 39.9) {
            result = "<b>You are on Obesity</b>";
        } else {
            result = "<b>Please enter correct data</b>";
        }

        document.querySelector('.result').style.display = "block";
        document.querySelector("#result").innerHTML = BMI.toFixed(2);
        displayMessage(result);
        clearInputs();
    }

    function displayMessage(message) {
        document.querySelector('.comment').innerHTML = `<span id="comment">${message}</span>`;
        document.querySelector('.comment').style.display = "block";
    }

    function clearInputs() {
        weightInput.value = '';
        heightInput.value = '';
    }
});
