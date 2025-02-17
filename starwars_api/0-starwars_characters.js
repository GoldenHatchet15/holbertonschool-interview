#!/usr/bin/node

const request = require('request');
const movieId = process.argv[2];
const url = `https://swapi-api.hbtn.io/api/films/${movieId}/`;

if (!movieId) {
  console.error('Usage: ./0-starwars_characters.js <Movie ID>');
  process.exit(1);
}

request(url, (error, response, body) => {
  if (error) {
    console.error(error);
    return;
  }
  const data = JSON.parse(body);
  const characters = data.characters;
  if (!characters) {
    console.error('Invalid Movie ID');
    return;
  }

  const fetchCharacter = (index) => {
    if (index >= characters.length) return;
    request(characters[index], (charError, charResponse, charBody) => {
      if (charError) {
        console.error(charError);
        return;
      }
      console.log(JSON.parse(charBody).name);
      fetchCharacter(index + 1);
    });
  };

  fetchCharacter(0);
});
