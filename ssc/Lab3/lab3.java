import java.util.ArrayList;

class argument_list {
    String index;
    String argument;
}

class macro_name {
    int Index;
    String Name;
    int definition_pointer;
    ArrayList<argument_list> A = new ArrayList<argument_list>();
}

class macro_definition {
    int index;
    String definition;
}

public class lab3 {

    public static String mapper(String s, ArrayList<argument_list> arg, ArrayList<macro_name> macro_list) {
        String ans = "";
        String[] temp = string_token.token(s, " ");
        boolean is_definition = true;
        for (int i = 0; i < temp.length; i++) {
            /* all the argument in arg */
            for (int j = 0; j < macro_list.size(); j++) {
                if (macro_list.get(j).Name.equals(temp[i])) {
                    ans += temp[i] + " ";
                    i++;
                    is_definition = false;
                    break;
                }
            }
            if (temp[i].charAt(0) == '&' && is_definition == true) {
                for (int j = 0; j < arg.size(); j++) {
                    if (temp[i].equals(arg.get(j).argument)) {
                        temp[i] = arg.get(j).index;
                    }
                }
            }

            ans += temp[i] + " ";
        }

        return ans;
    }

    public static void main(String[] args) {
        try {
            String input_data = reader.read();
            String[] output = string_token.token(input_data, "\n");
            String output_file = "";
            ArrayList<macro_name> macro_name = new ArrayList<macro_name>();
            ArrayList<macro_definition> macro_definition_table = new ArrayList<macro_definition>();
            ArrayList<argument_list> arg = new ArrayList<argument_list>();
            int count_macro = 0;
            for (int i = 0; i < output.length; i++) {
                String[] temp = string_token.token(output[i], " ");
                for (int j = 0; j < temp.length; j++) {
                    if (temp[0].equals("MACRO")) {
                        count_macro++;
                    }
                }
            }
            int count = 1;
            for (int i = 0; i < output.length; i++) {
                String[] temp = string_token.token(output[i], " ");
                /* Macro */
                if (temp[0].equals("MACRO")) {
                    i++;
                    temp = string_token.token(output[i], " ");
                    macro_name m = new macro_name();
                    m.Index = count++;
                    m.Name = temp[0];
                    m.definition_pointer = macro_definition_table.size() + 1;
                    macro_name.add(m);
                    macro_definition md = new macro_definition();
                    md.index = i;
                    md.definition = output[i];
                    macro_definition_table.add(md);
                    for (int j = 1; j < temp.length; j++) {
                        argument_list al = new argument_list();
                        al.index = "#" + j;
                        al.argument = temp[j];
                        m.A.add(al);
                        arg.add(al);
                    }
                } else if (!temp[0].equals("MEND") && count_macro > 0) {
                    macro_definition md = new macro_definition();
                    md.index = i;
                    md.definition = output[i];
                    macro_definition_table.add(md);
                } else if (temp[0].equals("MEND")) {
                    count_macro--;
                    macro_definition md = new macro_definition();
                    md.index = i;
                    md.definition = output[i];
                    macro_definition_table.add(md);
                } else {
                    output_file = output_file + '\n' + output[i];
                }
            }
            System.out.println("Macro Name Table:");
            for (int i = 0; i < macro_name.size(); i++) {
                System.out.println(macro_name.get(i).Index + " " + macro_name.get(i).Name + " "
                        + macro_name.get(i).definition_pointer);
            }
            for (int i = 0; i < macro_name.size(); i++) {
                System.out.println("Argument List Table for " + macro_name.get(i).Name);
                for (int j = 0; j < macro_name.get(i).A.size(); j++) {
                    System.out.println(macro_name.get(i).A.get(j).index + " " + macro_name.get(i).A.get(j).argument);
                }
            }
            System.out.println("Macro Definition Table:");
            for (int i = 0; i < macro_definition_table.size(); i++) {
                System.out
                        .println(i + 1 + " "
                                + mapper(macro_definition_table.get(i).definition, arg, macro_name));
            }
            System.out.println("Ouput File:");
            System.out.println(output_file);

        } catch (Exception e) {
            e.printStackTrace();
        }
    }

}
