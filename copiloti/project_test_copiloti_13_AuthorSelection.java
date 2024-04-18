class AuthorSelection {
    public void getAuthors() {
        String firstname = req.getParameter("firstname");
        String lastname = req.getParameter("lastname");
        String query = "SELECT * FROM authors WHERE firstname = '" + firstname + "' AND lastname = '" + lastname + "'";
        try {
            Statement stmt = conn.createStatement();
            ResultSet rs = stmt.executeQuery(query);
            while (rs.next()) {
                String author = rs.getString("firstname") + " " + rs.getString("lastname");
                out.println("<option value='" + author + "'>" + author + "</option>");
            }
        } catch (SQLException e) {
            e.printStackTrace();
    }
}