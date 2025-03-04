const axios = require('axios');
const cheerio = require('cheerio');

const url = 'https://example.com'; // Replace with the target website

const scrapeData = async () => {
    try {
        const { data } = await axios.get(url);
        const $ = cheerio.load(data);
        const results = [];

        $('h2').each((index, element) => {
            results.push($(element).text());
        });

        console.log(results);
    } catch (error) {
        console.error('Error fetching data:', error);
    }
};

scrapeData();

// To automate with cron jobs, add the following line to your crontab:
// * * * * * /path/to/node /path/to/this/script.js
