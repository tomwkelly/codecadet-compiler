const file = require(process.argv[2]);
const fs = require("fs");

const date = file.context.date;

const benchmarks = file.benchmarks.map((benchmark) => {
  return { date: date, ...benchmark };
});

const writer = fs.createWriteStream("output-benchmarks.json", {
  flags: "a",
});

benchmarks.forEach((benchmark) => {
  const out = JSON.stringify(benchmark);
  writer.write('{"index":{"_index":"benchmark","_type":"_doc"}}\n');
  writer.write(`${out}\n`);
});
