/**
 * @param {string} sentence
 * @return {boolean}
 */
var checkIfPangram = function (sentence) {
    let set = new Set();
    for (let x of sentence) set.add(x);
    return set.size == 26;
};