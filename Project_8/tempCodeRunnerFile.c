    if(n == 0) {
        if(i != 4){
            return 3;
        }else if(i == 4){
            return -3;
        }
    }else if(n == 1) {
        if(i != 4){
            return 6;
        }else if(i = 4){
            return -6;
        }
    }else if(n == 2) {
        if(i != 4){
            return 2;
        }else if(i == 4){
            return -2;
        }
    }else if(n == 3) {
        if(i != 4){
            return 7;
        }else if(i == 4){
            return -7;
        }
    }else{
        int restNumber=(foo(n-1, i+1));
        return foo(n - 1, i) + restNumber;
    }