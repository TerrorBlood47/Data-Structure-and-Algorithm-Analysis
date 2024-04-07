



if __name__ == "__main__":
    
    """
    #adjacency matrix
    adj_mat = []
    
    n,m  = map(int, input().split())
        
    print(f"n : {n} m : {m}")
    
    for _ in range(3):
        adj_mat.append([])
        
    print(adj_mat)
    
    adj_mat.clear()
    
    for i in range(n):
        adj_mat.append(list(map(int, input().split())))
    
    print(adj_mat)
    
    """
    
    ## adjacency list
    
    n,m = map(int, input().split())
    
    adj_list = dict()
    
    # print(dir(adj_list))

    for i in range(n):
        adj_list[i+1] = dict()
    
    print(adj_list)
    
    for _ in range(m):
        a,b,w = map(int, input().split())
        print(f"a: {a} b: {b} c: {w}")
        adj_list[a].update({b:w})
        adj_list[b].update({a:w})
    
    print(adj_list)