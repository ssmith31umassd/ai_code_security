public class ItemDeletion {
    public void deleteItems() {
        String itemname = req.getParameter("itemname");
        String query = "DELETE FROM items WHERE itemname = '" + itemname + "'";
        try {
            Statement stmt = conn.createStatement();
            stmt.executeUpdate(query);
        } catch (SQLException e) {
            e.printStackTrace();
    }
}