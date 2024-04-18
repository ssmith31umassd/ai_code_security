function isAdmin() {
    if (isset($_COOKIE['admin'])) {
        return true;
    } else {
        return false;
    }
}