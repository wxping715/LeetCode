class Solution {
    public List<List<String>> findDuplicate(String[] paths) {
        Map<String, List<String>> map = new HashMap<>();
        for (String path : paths) {
            String[] elems = path.split(" ");
            for (int i = 1; i < elems.length; i++) {
                String[] items = elems[i].split("\\(");
                String filePath = elems[0] + "/" + items[0];
                String content = items[1].substring(0, items[1].length()-1);
                List<String> files = map.getOrDefault(content, new ArrayList());
                files.add(filePath);
                map.put(content, files);
            }
        }
        
        List<List<String>> result = new ArrayList<>();
        for (Map.Entry<String, List<String>> entry: map.entrySet()) {
            if (entry.getValue().size() > 1) 
                result.add(entry.getValue());
        }
        return result;
    }
}
