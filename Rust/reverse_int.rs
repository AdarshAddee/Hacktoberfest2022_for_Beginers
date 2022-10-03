fn anti_str_reverse(x: i128) -> i128{
    let mut place_val: i128 = 0;
    let mut aux: i128 = x.abs();
    while aux > 0 {
        place_val = place_val * 10 + (aux % 10);
        aux /= 10
    }
    if x < 0 {
        return -place_val
    }
    return place_val

}