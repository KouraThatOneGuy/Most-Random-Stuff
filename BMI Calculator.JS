// Console-based BMI Calculator
function calculateBMI(height, weight) {
    // Validate inputs
    if (!height || !weight) {
        console.log('Error: Please provide both height and weight');
        return null;
    }
    
    if (height <= 0 || weight <= 0) {
        console.log('Error: Height and weight must be positive numbers');
        return null;
    }

    // Convert height from cm to meters
    const heightInMeters = height / 100;
    
    // Calculate BMI
    const bmi = weight / (heightInMeters * heightInMeters);
    
    // Determine BMI category
    let category;
    if (bmi < 18.5) category = 'underweight';
    else if (bmi < 25) category = 'normal';
    else if (bmi < 30) category = 'overweight';
    else category = 'obese';

    // Display results
    console.log('\n=== BMI Results ===');
    console.log(`BMI: ${bmi.toFixed(1)}`);
    console.log(`Category: ${category.charAt(0).toUpperCase() + category.slice(1)}`);
    console.log('==================\n');

    return { bmi, category };
}

// Example usage - feel free to modify these values!
const height = 165.1; // Height in centimeters
const weight = 50.6;  // Weight in kilograms

console.log(`Calculating BMI for:`);
console.log(`Height: ${height} cm`);
console.log(`Weight: ${weight} kg\n`);

calculateBMI(height, weight);
