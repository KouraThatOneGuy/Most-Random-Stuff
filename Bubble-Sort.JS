function bubbleSort(arr) {
    const arrayLength = arr.length;
    
    // Outer loop controls the number of passes
    for (let i = 0; i < arrayLength; i++) {
        console.log(`\nPass ${i + 1}:`);
        
        // Inner loop compares adjacent elements
        for (let j = 0; j < arrayLength - i - 1; j++) {
            console.log(`Comparing ${arr[j]} and ${arr[j + 1]}...`);
            
            // If elements are in wrong order, swap them
            if (arr[j] > arr[j + 1]) {
                console.log(`Swapping ${arr[j]} and ${arr[j + 1]}`);
                
                // Swap elements using destructuring
                [arr[j], arr[j + 1]] = [arr[j + 1], arr[j]];
                
                // Show array after swap
                console.log('Array:', [...arr]);
            } else {
                console.log('No swap needed');
            }
        }
        
        // Show state after each pass
        console.log('End of pass', i + 1);
        console.log('Current array:', [...arr]);
    }
    
    return arr;
}

// Test the sorting algorithm
const testArray = [64, 34, 25, 12, 22, 11, 90];
console.log('Original array:', testArray);
console.log('\nStarting bubble sort...\n');
const sortedArray = bubbleSort(testArray);
