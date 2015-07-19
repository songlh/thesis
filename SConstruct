env = Environment(
    tools=['pdflatex', 'pdftex', 'tex'],
    )

env.AppendUnique(PDFLATEXFLAGS='--synctex=1')
env.AppendUnique(LATEXRETRIES=7)

if env.GetOption('silent'):
    env.AppendUnique(
        PDFLATEXFLAGS=['-file-line-error', '-interaction=batchmode'],
        BIBTEXFLAGS='-terse',
        )

env.PrependENVPath('PATH', [
        '/local.toadette/songlh/github/thesis/install/tex/bin/x86_64-linux/',
        ])

pdf = env.PDF('dissertation.tex')[0]
Default(pdf)
Clean(pdf, pdf.target_from_source('', '.synctex.gz'))

ps = env.Command('dissertation.ps', pdf, 'pdftops $SOURCE $TARGET')

inkscape = env.WhereIs('inkscape')
if inkscape:
    traps = Dir('figures/traps')
    for state in ('locked', 'unlocked'):
        source = traps.File('%s.svg' % state)
        target = traps.File('%s.pdf' % state)
        env.Command(target, source, 'inkscape --export-pdf=$TARGET $SOURCE')
        
Depends(pdf, [
        Glob('figures/*.c'),
        Glob('figures/why-merge/*.txt'),
        Glob('figures/traps/*.c'),
        Glob('figures/traps/*.pdf'),
        Glob('figures/traps/*.tex'),
        ])
