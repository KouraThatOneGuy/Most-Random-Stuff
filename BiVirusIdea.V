# Maze Solver Algorithm

import os

fn read_input(file_path string) ?([][]int, [][]int) {
    content := os.read_file(file_path) ?
    lines := content.split('\n')
    dimensions := lines[0].split(' ').map(it.int())
    n := dimensions[0]
    
    mut walls_right := [][]int{cap: n}
    mut walls_bottom := [][]int{cap: n}
    
    for i in 1..n + 1 {
        walls_right << lines[i].split(' ').map(it.int())
    }
    
    for i in n + 1..2 * n + 1 {
        walls_bottom << lines[i].split(' ').map(it.int())
    }
    
    return walls_right, walls_bottom
}

fn solve_mazes(walls_right [][]int, walls_bottom [][]int) []string {
    mut instructions := []string{}
    x, y := 0, 0
    n := walls_right.len
    
    for x < n && y < n {
        if x == n - 1 && y == n - 1 {
            break
        }
        
        if y < n - 1 && walls_right[x][y] == 0 {
            instructions << 'right'
            y++
        } else if x < n - 1 && walls_bottom[x][y] == 0 {
            instructions << 'down'
            x++
        } else if y > 0 && walls_right[x][y - 1] == 0 {
            instructions << 'left'
            y--
        } else if x > 0 && walls_bottom[x - 1][y] == 0 {
            instructions << 'up'
            x--
        }
    }
    
    return instructions
}

fn main() {
    walls_right, walls_bottom := read_input('input.txt') or {
        println('Error reading input file')
        return
    }
    
    instructions := solve_mazes(walls_right, walls_bottom)
    println(instructions)
}
