/**
 * @param {number[][]} grid
 * @return {boolean}
 */

let m, n;
let visited;

// 1,2,3,4,5,6
const canRight = [false, true, false, false, true, false, true];
const canLeft  = [false, true, false, true, true, true, false];
const canUp    = [false, false, true, false, false, true, true];
const canDown  = [false, false, true, true, true, false, false];

const dirs = [[0,1],[0,-1],[-1,0],[1,0]]; // right, left, up, down

var hasValidPath = function(grid) {
    m = grid.length;
    n = grid[0].length;
    visited = Array.from({ length: m }, () => Array(n).fill(false));
    return dfs(0, 0, grid);
};

function dfs(r, c, grid) {
    if (r === m - 1 && c === n - 1)
        return true;

    visited[r][c] = true;

    for (let i = 0; i < 4; i++) {
        const nr = r + dirs[i][0];
        const nc = c + dirs[i][1];

        if (
            nr >= 0 && nr < m &&
            nc >= 0 && nc < n &&
            !visited[nr][nc] &&
            canMove(grid[r][c], grid[nr][nc], i)
        ) {
            if (dfs(nr, nc, grid))
                return true;
        }
    }

    return false;
}

function canMove(curr, next, dir) {
    if (dir === 0) { // right
        return canRight[curr] && canLeft[next];
    } else if (dir === 1) { // left
        return canLeft[curr] && canRight[next];
    } else if (dir === 2) { // up
        return canUp[curr] && canDown[next];
    } else if (dir === 3) { // down
        return canDown[curr] && canUp[next];
    }

    return false;
}