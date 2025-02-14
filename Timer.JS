// Timer implementation
function Timer() {
    this.startTime = null;
    this.intervalId = null;
    this.isRunning = false;
}

Timer.prototype.start = function() {
    if (this.isRunning) {
        console.log('Timer is already running!');
        return;
    }

    this.startTime = Date.now();
    this.isRunning = true;

    console.log('\nTimer started!');
    console.log('Type "stop" to stop the timer, "reset" to reset it');

    this.intervalId = setInterval(() => {
        const elapsed = Date.now() - (this.startTime || 0);
        const seconds = Math.floor(elapsed / 1000);
        const minutes = Math.floor(seconds / 60);
        const hours = Math.floor(minutes / 60);

        const timeString = `${hours.toString().padStart(2, '0')}:${minutes.toString().padStart(2, '0')}:${seconds.toString().padStart(2, '0')}`;
        console.log(`\rTime elapsed: ${timeString}`, '');
    }, 1000);
}

Timer.prototype.stop = function() {
    if (!this.isRunning) {
        console.log('\nTimer is not running!');
        return;
    }

    if (this.intervalId) {
        clearInterval(this.intervalId);
    }

    const elapsed = Date.now() - (this.startTime || 0);
    const seconds = Math.floor(elapsed / 1000);
    const minutes = Math.floor(seconds / 60);
    const hours = Math.floor(minutes / 60);

    console.log('\nTimer stopped!');
    console.log(`Final time: ${hours}:${minutes.toString().padStart(2, '0')}:${seconds.toString().padStart(2, '0')}`);
    this.isRunning = false;
}

Timer.prototype.reset = function() {
    if (this.intervalId) {
        clearInterval(this.intervalId);
    }
    this.startTime = null;
    this.isRunning = false;
    console.log('\nTimer reset!');
    console.log('Time elapsed: 00:00:00');
}

// Create timer instance
const timer = new Timer();

// Example usage
console.log('Timer Controls:');
console.log('Type "start" to begin the timer');
console.log('Type "stop" to stop the timer');
console.log('Type "reset" to reset the timer\n');

// Start the timer
timer.start();
