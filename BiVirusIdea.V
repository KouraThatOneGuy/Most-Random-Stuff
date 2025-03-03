# Maze Solver Algorithm

fn solve_mazes(maze1 [][]int, maze2 [][]int) []string {
    mut instructions := []string{}
    pos1 := [0, 0]
    pos2 := [0, 0]
    
    for pos1 != [maze1.len() - 1, maze1[0].len() - 1] || pos2 != [maze2.len() - 1, maze2[0].len() - 1] {
        if can_move(pos1, maze1) {
            pos1 = move(pos1, 'down')
            instructions << 'down'
        }
        if can_move(pos2, maze2) {
            pos2 = move(pos2, 'down')
            instructions << 'down'
        }
        if can_move(pos1, maze1) {
            pos1 = move(pos1, 'right')
            instructions << 'right'
        }
        if can_move(pos2, maze2) {
            pos2 = move(pos2, 'right')
            instructions << 'right'
        }
    }
    return instructions
}

fn can_move(pos []int, maze [][]int) bool {
    return maze[pos[0]][pos[1]] == 0
}

fn move(pos []int, direction string) []int {
    match direction {
        'up' { return [pos[0] - 1, pos[1]] }
        'down' { return [pos[0] + 1, pos[1]] }
        'left' { return [pos[0], pos[1] - 1] }
        'right' { return [pos[0], pos[1] + 1] }
        else { return pos }
    }
}


