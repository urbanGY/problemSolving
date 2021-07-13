@see {@link https://programmers.co.kr/learn/courses/30/lessons/81301}

function solution(s) {
  const map = {
    zero: "0",
    one: "1",
    two: "2",
    three: "3",
    four: "4",
    five: "5",
    six: "6",
    seven: "7",
    eight: "8",
    nine: "9",
  };
  var answer = "";
  let tmp = "";
  for (let c of s) {
    if (c >= "0" && c <= "9") {
      answer += c;
    } else if (map[tmp + c]) {
      answer += map[tmp + c];
      tmp = "";
    } else {
      tmp += c;
    }
  }

  return Number(answer);
}
