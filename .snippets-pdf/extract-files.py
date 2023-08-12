import os
import re
import argparse
from typing import List

# Create the argument parser
parser = argparse.ArgumentParser(description='Extract snippets each in separate file using a snippets file (cpp.snippets)')

# Add the arguments
parser.add_argument('-s', '--snippets', type=str, help='Source snippets file path')
parser.add_argument('-o', '--output', type=str, help='Output directory path')

# Parse the command-line arguments
args = parser.parse_args()

# Access the values of the arguments
snippets_file = args.snippets
output_directory = args.output
sections_tex = []


def get_section(title, filepath):
    return f"\\section{{{title}}}\n" + \
        f"\\raggedbottom\\lstinputlisting[style=cpp]{{{filepath}}}"


def escape_latex_symbols(text):
    symbols = {'&', '{', '}'}
    pattern = re.compile('(' + '|'.join(re.escape(symbol) for symbol in symbols) + ')')
    escaped_text = pattern.sub(r'\\\1', text)
    return escaped_text


def remove_indent(snip, indent=' '*4):
    return '\n'.join([
        (l[len(indent):] if len(l)>=len(indent)and l[:len(indent)] == indent else l)
        for l in snip.split('\n')
    ])


with open(snippets_file, 'r') as f:
    content = f.read()
    content += "\n#"
    pattern = re.compile(r'^(?:#(.*?))\nsnippet (\w+)([\s\S]*?)(?=^#)', flags=re.IGNORECASE | re.MULTILINE)
    result: List[str] = pattern.findall(content)

    for title, snip_name, snip in result:
        title = escape_latex_symbols(title.strip().capitalize())
        filepath = os.path.join(output_directory, f'{snip_name}.cpp')
        with open(filepath, 'w') as f:
            f.write(remove_indent(snip).strip() + "\n")
        sections_tex.append(get_section(title, filepath))

with open('src/sections.tex', 'w') as f:
    f.write("\n\n".join(sections_tex))

