    /**
     * @param {string} s
     * @return {boolean}
     */
    var isNumber = function(s) {
        // 思路：有限自动机
        const states = [
            { ' ': 0, 's': 1, 'd': 2, '.': 4 },
            { '.': 4, 'd': 2 },
            { 'd': 2, '.': 3, 'e': 5, ' ': 8 },
            { 'd': 3, 'e': 5, ' ': 8 },
            { 'd': 3 },
            { 's': 6, 'd': 7 },
            { 'd': 7 },
            { 'd': 7, ' ': 8 },
            { ' ': 8 }
        ]
        let p = 0

        for (let i = 0; i < s.length; i++) {
            let t = s[i]
            if (s[i] >= '0' && s[i] <= '9') {
                t = 'd'
            } else if (s[i] == 'e' || s[i] == 'E') {
                t = 'e'
            } else if (s[i] == '+' || s[i] == '-') {
                t = 's'
            } else if (s[i] == '.') {
                t = '.'
            } else if (s[i] == ' ') {
                t = ' '
            } else {
                return false
            }
            
            if (typeof states[p][t] === 'undefined') {
                return false
            }

            p = states[p][t]
        }
        
        return p == 2 || p == 3 || p == 7 || p == 8;
    };