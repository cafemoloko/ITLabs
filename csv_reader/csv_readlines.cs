using System.IO;
using System.Text;

namespace csv_readlines
{
    class Program
    {
        static void Main(string[] args)
        {
            using (var reader = new StreamReader("heroes.csv"))
            using (var fileStream = new FileStream("heroes.html", FileMode.OpenOrCreate))
            using (var streamWriter = new StreamWriter(fileStream))
            {
                var wroteHeader = false;
                streamWriter.WriteLine("<html>\n<body>\n<table>");
                streamWriter.WriteLine("<table border='1px' cellpadding='1' cellspacing='1' bgcolor='lightgrey'" + 
                                       "style='font-family:Arial; font-size:12px'>");
                while (!reader.EndOfStream)
                {
                    var line = reader.ReadLine();
                    var values = line.Split(';');
                    if(!wroteHeader) //header
                    {
                        var outputLine = new StringBuilder("<thead>\n<tr>\n");
                        
                        foreach(var value in values)
                        {
                            outputLine.Append(string.Format("<th>{0}</th>\n", value));
                        }
                        outputLine.Append("</tr>\n</thead>\n<tbody>");
                        streamWriter.WriteLine(outputLine);
                        wroteHeader = true;
                    } 
                    else //lines
                    {
                        var outputLine = new StringBuilder("<tr>\n");
                        foreach(var value in values)
                        {
                            outputLine.Append(string.Format("<td>{0}</td>\n", value));
                        }
                        outputLine.Append("</tr>");
                        streamWriter.WriteLine(outputLine);
                    }
                }
                streamWriter.WriteLine("</tbody>\n</table>\n</body>\n</html>");
            }
        }
    }
}
