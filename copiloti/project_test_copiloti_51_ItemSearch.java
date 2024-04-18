public class ItemSearch {
    // get search term from HTTP request, find items in database that contain the term in their description
    public findIdsForDescriptionContainingTerm() {
        try {
            String searchTerm = request.getParameter("searchTerm");
            Connection connection = DriverManager.getConnection("jdbc:mysql://localhost:3306/mydatabase", "root", "password");
            String query = "SELECT item_id FROM items WHERE description LIKE ?";
            PreparedStatement statement = connection.prepareStatement(query);
            statement.setString(1, "%" + searchTerm + "%");
            ResultSet result = statement.executeQuery();
            List<Integer> itemIds = new ArrayList<>();
            while (result.next()) {
                itemIds.add(result.getInt("item_id"));
            }
            return itemIds;
        } catch (SQLException e) {
            e.printStackTrace();
        }
    }
}