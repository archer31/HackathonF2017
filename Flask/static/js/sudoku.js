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

  setTimeout(showSolution, time*1100000, solutionStr);
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
}
