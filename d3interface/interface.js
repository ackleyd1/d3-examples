var Module = {
    onRuntimeInitialized: function() {
      console.log('lerp result: ' + Module.lerp(1, 2, 0.5));
    }
  };

  const height = 5
const width = 15
const margin = ({top: 0, right: 0, bottom: 0, left: 0})
const data = [5.1, 4.9, 8.6, 6.2, 5.1, 7.1, 6.7, 6.1, 5, 5, 5.2, 7.9, 11.1, 5.9, 5.5, 5.6, 6.5, 7.7, 5.7, 6.7]
const bins = d3.bin().thresholds(4)(data)
const color = "steelblue"

// x and y scales
x = d3.scaleLinear()
    .domain([bins[0].x0, bins[bins.length - 1].x1])
    .range([margin.left, width - margin.right])

y = d3.scaleLinear()
    .domain([0, d3.max(bins, d => d.length)]).nice()
    .range([height - margin.bottom, margin.top])

// define xAxis and yAxis functions called by group elements
xAxis = g => g
    .attr("transform", `translate(0,${height - margin.bottom})`)
    .call(d3.axisBottom(x).ticks(width / 80 ).tickSizeOuter(0))

yAxis = g => g
    .attr("transform", `translate(${margin.left},0)`)
    .call(d3.axisLeft(y))
    .call(g => g.select(".domain").remove())

// create svg
const svg = d3.select("body").append("svg")
    .attr("viewBox", [0,0, width, height]);

// create histogram svg
svg.append("g").attr("fill", color)
    .selectAll("rect")
    .data(bins)
    .join("rect")
        .attr("x", d => x(d.x0) + 1)
        .attr("width", d => Math.max(0, x(d.x1) - x(d.x0) - 1))
        .attr("y", d => y(d.length))
        .attr("height", d => y(0) - y(d.length));


svg.append("g").call(xAxis);
svg.append("g").call(yAxis);
