function createPlayerGrid(puzzleStr)
{
  puzzleArray = puzzleStr.split("")
  var iter=0;
  for(var i=1; i<=9; i++)
  {
    for(var j=1; j<=9; j++, iter++)
    {
      var id = (""+i)+j;
      var val = puzzleArray[iter];
      if(val == "0") {
        document.getElementById(id).setAttribute("contenteditable", 'true');
      } else {
        document.getElementById(id).innerHTML = val;
      }
    }
  }
}

function createAIGrid(solutionStr, puzzleStr, time)
{
  puzzleArray = puzzleStr.split("")
  var iter=0;
  for(var i=1; i<=9; i++)
  {
    for(var j=1; j<=9; j++, iter++)
    {
      var id = ("1"+i)+j;
      var val = puzzleArray[iter];
      if(val == "0") {
        document.getElementById(id).innerHTML = '-';
      } else {
        document.getElementById(id).innerHTML = val;
      }
    }
  }

  setTimeout(showSolution, time*110000, solutionStr);
}

function showSolution(solutionStr) {
  puzzleArray = solutionStr.split("")
  var iter=0;
  for(var i=1; i<=9; i++)
  {
    for(var j=1; j<=9; j++, iter++)
    {
      var id = ("1"+i)+j;
      var val = puzzleArray[iter];
      document.getElementById(id).innerHTML = val;
    }
  }

  if(checkSolution()) {
    document.getElementById('victory').classList.remove("hide-message");
    document.getElementById('victory').classList.add("show-message");
  }
  else
  {
    document.getElementById('failure').classList.remove("hide-message");
    document.getElementById('failure').classList.add("show-message");
  }
}

function checkSolution()
{
  var grid = new Array(9);
  for(var i=0; i<9; i++) {
    grid[i] = new Array(9);
  }

  var iter = 0;
  for(var i=1; i<=9; i++)
  {
    for(var j=1; j<=9; j++, iter++)
    {
      var id = (""+i)+j;
      var val = puzzleArray[iter];

      grid[i-1][j-1] = val;
    }
  }

  return validSudoku(grid);
}

function validSudoku(data) {
    var valid = true, 
        temp = [], 
        data,
        side,
        slot;


    // Check wrong size
    if (data[0].length !== data.length) valid = false;

    // slot*slot
    slot = Math.sqrt(data.length);

    // Verifiy horizontal
    data.forEach(function(arr) {
        valid = valid && arr.every(function(val, i) { return arr.indexOf(i + 1) > -1; });
    });

    // Verifiy vertical lines
    data.forEach(function(arr, i) {
        temp  = data.map(function(val) { return val[i]; });
        valid = valid && arr.every(function(val, i) { return temp.indexOf(i + 1) > -1; });
    });

    // Verifiy boxes
    for (var i = 0; i < slot; i++) {

        data.forEach(function(val, e) {
            side  = val.slice(slot * i, slot * i + slot);
            temp  = temp.concat(side);

            if ((e+1) % slot == 0 && e > 0) {
                for (var j = 1; j <= data.length; j++)
                    if (temp.indexOf(j) < 0) valid = false;                 
                temp = [];
            }

        });

    }
    return valid;
}

